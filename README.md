# Morse Code Detector using Machine Learning

This project implements a Morse code detector using machine learning techniques, specifically the Random Forest classifier. The system takes input signals, converts them to English characters, and then trains an ESP32 microcontroller to interpret Morse code signals in real-time.

## Overview

The Morse code detector comprises several components and steps:

1. **Random Forest Classifier**: Uses a Random Forest classifier in Python to detect and classify Morse code signals from audio or visual input.

2. **Training with Real Data**: Trains the algorithm using real Morse code signals, captured during both training and testing phases, to improve accuracy and reliability

3. .**Conversion to C**: Converts the Python output to C code using the Micromelgen module, enabling the implementation of the algorithm on embedded systems.

4. **English Conversion**: Produces English converted output from the Morse code signals detected by the classifier.

5. **ESP32 Implementation**: Trains an ESP32 microcontroller using the Arduino IDE to interpret Morse code signals in hardware.

## Components Used

- Python (scikit-learn library for Random Forest classifier)
- Micromelgen module for converting Python output to C code
- ESP32 microcontroller
- Arduino IDE for ESP32 development

## Setup Instructions

1. **Python Setup**: Install the required Python packages, including scikit-learn and Micromelgen, using `pip install scikit-learn micromelgen`.

2. **Data Collection**: Collect real Morse code signals for training and testing the classifier.

3. **Random Forest Classifier**: Train the Random Forest classifier using the collected data.

4. **Conversion to C**: Convert the Python output to C code using the Micromelgen module.

5. **ESP32 Implementation**: Train the ESP32 microcontroller using the Arduino IDE and upload the C code to interpret Morse code signals in real-time.

## Usage

1. **Run Python Script**: Execute the Python script to detect Morse code signals and produce English converted output.

2. **Train ESP32**: Upload the trained C code to the ESP32 microcontroller using the Arduino IDE.

3. **Hardware Implementation**: Connect the ESP32 to the hardware setup (e.g., audio or visual input) and observe real-time Morse code interpretation.

## Contributions

Contributions to enhance and expand the functionality of this Morse code detector project are welcome. Feel free to submit pull requests or raise issues for any bugs or feature requests.

## License

This project is licensed under the [MIT License](LICENSE). You are free to use, modify, and distribute the code for your own projects.



## Screenshots

**Output**

![Output](https://github.com/adarshsonkusre/Morse-Code-Detector/assets/115790171/c9537ade-2690-41b8-9a72-b80c5328c32e)


**Code Screenshots**

![image](https://github.com/adarshsonkusre/Morse-Code-Detector/assets/115790171/577cc84f-c84a-4fbf-ae4c-c0a40905334f)






