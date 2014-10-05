# Executrix Button

## Dependencies
### Hardware
- 1 x Big Button. I'm using an [NHP Roughneck](http://www.nhp.com.au/files/editor_upload/file/product-tools/arough.pdf)
- 1 x [Adafruit Trinket](https://learn.adafruit.com/introducing-trinket/introduction)

### Firmware
1. [Adafruit Arduino IDE](https://learn.adafruit.com/introducing-trinket/setting-up-with-arduino-ide)
2. (Optional) [ino](http://inotool.org/) to build and deploy from the command-line. Currently there is no support for `.S` assembly file
   compilation in `ino`, so use my [fork of a fork](https://github.com/joshbode/ino):

      $ pip install -e "git+git://github.com/joshbode/ino.git@assembly_file_support#egg=ino"
      $ ln -s /Applications/Adafruit\ Arduino\ 1.0.5.app /Applications/Arduino.app
