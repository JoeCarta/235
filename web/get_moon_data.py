from astroquery.jplhorizons import Horizons
from astropy.time import Time
from astropy.coordinates import SkyCoord
import astropy.units as u
import datetime
import numpy as np
import json

# Observer location: New York City
observer = {'lon': -74.0060, 'lat': 40.7128, 'elevation': 10}

# Current time (UTC -> JD)
now = datetime.datetime.now(datetime.timezone.utc)
jd = Time(now).jd

# Galilean moon IDs
moons = {'Io': '501', 'Europa': '502', 'Ganymede': '503', 'Callisto': '504'}


def get_coord(body_id):
    eph = Horizons(id=body_id, location=observer, epochs=[jd]).ephemerides()
    return (
        SkyCoord(ra=eph['RA'][0] * u.deg, dec=eph['DEC'][0] * u.deg, frame='icrs'),
        eph['EL'][0],
        eph['AZ'][0],
    )


jupiter, _, _ = get_coord('599')
moon_data = {name: get_coord(mid) for name, mid in moons.items()}


def get_offsets(moon_coord, jup_coord):
    delta_ra = (moon_coord.ra - jup_coord.ra).wrap_at(180 * u.deg)
    delta_ra = (delta_ra * np.cos(jup_coord.dec)).to(u.arcsec)
    delta_dec = (moon_coord.dec - jup_coord.dec).to(u.arcsec)
    return delta_ra.value, delta_dec.value


output = {
    'jupiter': {'ra': jupiter.ra.deg, 'dec': jupiter.dec.deg},
    'moons': {},
    'time_iso': Time(now).iso,
}

for name, (coord, alt, az) in moon_data.items():
    dra, ddec = get_offsets(coord, jupiter)
    output['moons'][name] = {
        'dra': dra,
        'ddec': ddec,
        'alt': alt,
        'az': az,
    }

with open('web/moons.json', 'w') as f:
    json.dump(output, f, indent=2)
print('Wrote data to web/moons.json')
