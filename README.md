# readme

## Galilean Moons Plot

A simple Python script and HTML page have been added in the `web` directory.
Run the script to generate `moons.json` with the current positions of Jupiter's
Galilean moons and open `index.html` in a browser to see the plot.

### Steps

1. Install dependencies:
   ```bash
   pip install astroquery astropy numpy matplotlib
   ```
2. Generate the data file:
   ```bash
   python web/get_moon_data.py
   ```
3. Open `web/index.html` in your browser. The page loads `moons.json` and
   displays the moon positions using Plotly.
