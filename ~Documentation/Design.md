# id_expl0rer_0 Game Design

## Summary

id_expl0rer is an incremental game focused on physical activity and gathering new data of the world around you. 

## Gameplay

The game is played on a device that can collect physical activty data, and locational data.

- The physical activity will increment a point counter.
- The incremental point value can be altered with modifiers.
- Sensors in your device gather information on the world around you.
- The data is used to mine new modifiers.
- The mined modifiers are purchaseable with points, or recycled for points.
- Modifiers will stack and apply on a FIFO order.

## Target Devices

The game is targeted at a broad range of devices capable of handling the task.

- pocket esp32 development devices with display, buttons & accelerameters
- Nintendo 3DS Homebrew
- Motorola WT4070 Wearable Terminal
- Smartphones
- Smartwatches

## Software Design

The software will be split into two primary parts.

1. A shell that builds to individual target devices.
2. A core that contains logic that all shells share.

## Sample 

The sample will be a demo game built to run in a common console window.
The sample will also include a developer tool to test core functionality for rapid development.

## Graphics

The game should be playable with a tiny low res monochrome display like a Tomagachi from the 90's, and devices limited to a serial console.

Graphics should be limited to monospaced ASCII symbols & 8 bit & monochrome pixel art.

## Input

Primary interaction with the game will be through acceleramter, step counter or a heart rate monitor & at least one secondary data collection method for mining.

There will need to be a way for the user to purchace or recycle mined modifiers. Idealy at least two buttons.

