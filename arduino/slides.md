---
Author: Hamish Hutchings
title: Arduino IDE
email: "@hamhut1066"
---

# What?

- Installing Arduino IDE
- Configuring IDE
- Getting something onto our hardware
- Try out something basic

---

# Disclaimer

- Everything is being done in a VM

---

# Installing Arduino IDE

- Dependencies: `apt get install openjdk-11-jdk-headless bossa-cli
- Install the IDE https://www.arduino.cc/en/main/software
  - Extract downloaded file
  - Run `./install.sh`
- Add yourself to the `dialout` group

---

# Configure IDE

- Open preferences
- Add [1] to 'Boards Manager URLs'
- Tools -> Boards -> BoardManager
- Search 'Adafruit SAMD'
- Install 'Adafruit SAMD Boards'

[1]: https://adafruit.github.io/arduino-board-index/package_adafruit_index.json

---

# Getting something onto our Hardware

- Put it into flash mode
- Select File -> Examples -> Basic -> Blink
- Select 'Upload'

---

# Let's build a die

Let's see what happens
