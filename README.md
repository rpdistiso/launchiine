## Launchiine (WIP)

A simple Wii U Menu replacement, still in early development and not ready for a day to day usage

## Usage (Replace Wii U Menu via Mocha Payload):
([ENVIRONMENT] is a placeholder for the actual environment name)
- Place the `men.rpx` on the SD card in the directory `sd:/wiiu/environments/[ENVIRONMENT]/`
- Load the [MochaPayload](https://github.com/wiiu-env/MochaPayload) via the [EnvironmentLoader](https://github.com/wiiu-env/EnvironmentLoader) (e.g. [Tiramisu](https://github.com/wiiu-env/Tiramisu) or [Aroma](https://github.com/wiiu-env/Aroma))
- Load the Wii U Menu and launchiine should show up instead

## Known Issues
- Random crashes
- The Keyboard input is implemented, but result is ignored
- nn::spm is initalized but no quick start menu support. It's relying on the [AutobootModule](https://github.com/wiiu-env/AutobootModule)
- Probably a lot more

## TODOs
- Non-touch controls (Must touch gamepad then you will be able to use DPad and analog sticks)
- Sound on splashscreen(Fixed sort of)
- Folder support
- Preserve app order after closing/opening launchiine.
- Display applets like the original Wii U Menu 
- Implement Account selection when no default account is set. 
- Implement update check/no way to update games
- Properly implement nn:sl (external storage and quick start menu)
- Fix search
- Implement all the other stuff the Wii U Menu offers (Account creation, switching between Accounts, set default account etc.)
- Implement ways to launch the original Wii U Menu.

## Building
Install the following dependencies:
- [wut](https://github.com/devkitPro/wut)
- [libgui](https://github.com/wiiu-env/libgui)

Then build via `make`.

## Building using the Dockerfile
Note: You must build libgui from `src/libgui` in this repository

It's possible to use a docker image for building. This way you don't need anything installed on your host system.

```
# Build docker image (only needed once)
docker build . -t launchiine-builder

# make 
docker run -it --rm -v ${PWD}:/project launchiine-builder make

# make clean
docker run -it --rm -v ${PWD}:/project launchiine-builder make clean
```

## Credits
Maschell: Libgui, AutoBootModule, original project

Dimok: FreeType and related assets
