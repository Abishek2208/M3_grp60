# Introduction
To work, keyless remotes have a short-range radio transmitter that must be within a set range of the automobile, usually 5–20 metres. When a button is pressed, radio waves transmit a coded signal to a receiver device in the car, which locks or unlocks the door.
# Bicom System
The extension of a unidirectional RKE system to a bidirectional RKE system is known as a BiCom system. car -> keyfob (like a unidirectional RKE system) keyfob -> car (car status information for displaying on the keyfob by LED or display)

The following are examples of BiCom status information sent to the keyfob: Print the current state of the window (Blue switch on- All led on at the same time) (Blue switch pressed twice-all leds turned off at the same time) Print alarm status Information about car batteries can be printed out – (Blue switch press three times- All led on in clockwise manner) Print the current status of the door (Blue switch press four times- All led on in anti-clockwise manner)

# High Level Requirements 
 | ID    |	  High level requirements             |
 |-------|----------------------------------------|
 |  HL1	 |  Transmitter is required to transmit RF signals from the key |
 |  HL2	 |  Receiver is required to receive and verify the signal |
 |  HL3	 |  Print window status when blue switch on |
 |  HL4	 |  Print car battery info when blue switch press three times |
 |  HL5	 |  Print Door status when blue switch press four times |
 
 # Low Level Requirements
| ID	 |     LOW level requirements  |
|------|-----------------------------|
| LL1	 |     All LEDs should turn ON at the same time when blue switch pressed once |
| LL2	 |     All LEDs should turn OFF at the same timewhen blue switch pressed twice |
| LL3	 |     All LEDs should turn ON in clockwise manner when blue switch pressed thrice |
| LL4 |	    All LEDs should turn ON in anticlockwise manner when blue switch pressed 4 times |

# SWOT Analysis
 ### Strengths
* Highly secure as it is, mananged by buttons
* Limited Human Interaction

### Weakness
* Delay between the commands
* The range is limited

### Opportunites
* It has high scope in automotive industry
* Budget needed is less

### Threat
* Delay can be severe concern

# 4W's and 1H
![5w](https://user-images.githubusercontent.com/46948689/157864263-a657a3b1-d2a8-4f24-a035-f4f2c81d1dd8.jpg) 

## High Level Block Diagram

![high_level_behavioural](https://user-images.githubusercontent.com/46948689/157864728-f4f65e49-d2f9-4f0d-8943-1f7058e0ac05.png)

## Low Level Block Diagram
![low_level_behavourial](https://user-images.githubusercontent.com/46948689/157864810-cb5238ab-b04d-4476-a443-b793c177a025.png)

## Structural Diagram
![structural_diagram](https://user-images.githubusercontent.com/46948689/157864951-f4da5098-ea02-4dd2-a808-bc6ca3264293.png)
## Test Plan

|SL. ID	|  Description	         |        Given input	       |           Experiemented Output    |                    Actual Output	         |      Passed or Not  |                                                   
|-------|------------------------|---------------------|-----------------------------------|------------------------------------------------|-----------------
| 01	| Display Window status	 |  Pressing button one time      |	 All LED's ON at same time	        |        All LED's ON at same time	         |               Yes  |
| 02	| Display Alarm status	 |  Pressing button two times     |	 All LED's OFF at same time	        |       All LED's OFF at same time	         |               Yes    |
| 03	| Display Car battery info |  Pressing button three times   |	 All LED's ON in clockwise manner       |        All LED's ON in clockwise manne 	 |             Yes    |
| 04	| Display Door status	 |  Pressing button four times    |	 All LED's ON in anti-clockwise manner	|        All LED's ON in anti-clockwise manner   |	         Yes    |

![SCREENSHOT](https://user-images.githubusercontent.com/98824204/157932796-938daccd-e629-4a1f-9efe-bbe7b229fc6b.jpg)

## Applications
Other uses for the BiCom system include

* Sliding roofs, sliding doors, and tailgates are all more convenient to open and close.

* For further security, the key has a "emergency button" built in.

* At the touch of a button, it activates an audio and visual alarm in the vehicle.

