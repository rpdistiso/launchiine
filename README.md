## Launchiine (WIP)

A simple Wii U Menu replacement, currently in an alpha development stage and not ready for day to day usage

## Usage (Replace Wii U Menu via Mocha Payload):
[ENVIRONMENT] is a placeholder for the actual environment name
- Place the `men.rpx` on the SD card in the directory `sd:/wiiu/environments/[ENVIRONMENT]/`
- Load the [MochaPayload](https://github.com/wiiu-env/MochaPayload) via the [EnvironmentLoader](https://github.com/wiiu-env/EnvironmentLoader) (e.g. [Tiramisu](https://github.com/wiiu-env/Tiramisu) or [Aroma](https://github.com/wiiu-env/Aroma))
- Load the Wii U Menu and Launchiine should appear instead

## Known Issues
- Random crashes (Mainly related to GX2)
- The Keyboard input is implemented, but result is ignored
- `nn::spm` is initalized(see commit [`523f64f`](https://github.com/rpdistiso/launchiine/commit/523f64fb27ea9d9551ddc057f5cef03c75973339)) but no quick start menu support
- Probably a lot more

## TO-DOs
- Non-touch controls (Must touch gamepad then you will be able to use DPad and analog sticks)
- Folder support
- Preserve app order after closing/opening Launchiine
- Display applets like the original Wii U Menu 
- Implement Account selection when no default account is set
- Implement update check/no way to update games
- Properly implement `nn::sl` (external storage and quick start menu)
- Fix search
- Implement all the other stuff the Wii U Menu offers (Account creation, switching between Accounts, set default account etc.)
- Implement ways to launch the original Wii U Menu

## Building
Install the following dependencies:
- [wut](https://github.com/devkitPro/wut)
- [libgui](https://github.com/wiiu-env/libgui)

Then build via `make`

## Building using the Dockerfile
It's possible to use a docker image for building. This way you don't need anything installed on your host system

*Note: I highly recommend building via Docker*

```
# Build docker image (only needed once)
docker build . -t launchiine-builder

# make 
docker run -it --rm -v ${PWD}:/project launchiine-builder make -j2

# make clean
docker run -it --rm -v ${PWD}:/project launchiine-builder make clean
```

## Credits
Maschell: Libgui, AutoBootModule, original project

Dimok: FreeType and related assets
