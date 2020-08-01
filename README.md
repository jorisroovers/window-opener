# WindowOpener

I built a custom PCB in a 3D-printed enclosure to control a motorized arm to automatically open and close my bedroom window. 
All integrated with [my existing home automation stack](https://github.com/jorisroovers/casa). For much more detail, read the related blog post (TODO :-)).

This repository contains all related source material.

# Repository Structure
- `PCB/`: PCB related files in various formats. For easy editing, use the json file to import into [EasyEDA](https://easyeda.com/).
- `esphome/`: [ESPHome](https://esphome.io/) config files
- `CAD/`: CAD (3D) models of the enclosure and custom hinges that were 3D printed. I used [Fusion360](https://www.autodesk.com/products/fusion-360/personal).
- `diagrams/`: Some diagrams in [Fritzing](https://fritzing.org/) and [KiCad](https://kicad-pcb.org/). Some of these are not entirely up-to-date with the latest build, but they should still be useful if you want to understand some of the details.
- `gcode/`: gcode files to print the 3D models. These are mostly for my own consumption as you'll probably have re-slice the STL files in the `CAD/` folder to match your printer and filament.
- `archive/`: various files related to prototyping and experimentation

# ESPHome

# Flashing firmware to ESP8266 device

## secrets.yaml
The `window_opener.yaml` has secret values which are read by ESPHome from  `secrets.yaml` at compile-time.
So for this to work, you'll need to create a `secrets.yaml` file that looks like the following.
```yaml
deviceid: my_device_id
devicename: "Human Friendly Device Name"

wifi_ssid: mywifissid
wifi_password: "mypassword"
wifi_static_ip: 10.0.0.2
wifi_gateway: 10.0.0.1
wifi_subnet: 255.255.255.0
wifi_fallback_ap_password: "WifiFallbackPassword"
wifi_fallback_ap_ssid: ESP-FallbackWifi
api_password: "apipassword"
ota_password: "otapassword"
```

## Instructions

The first time doing this, the ESP device will need to be connected to your computer using a serial connection.
After the first run, you can do this over Wifi (ESPHome supports over-the-air firmware updates).

```sh
virtualenv .venv && source .venv/bin/activate
pip install esphome

esphome esphome/window_opener.yaml run
# Specify serial port
esphome esphome/window_opener.yaml run --upload-port /dev/cu.usbserial-143230
```

# Homeassistant Integration

Use the 'integrations' page in home-assistant to connect to the ESPHome device.