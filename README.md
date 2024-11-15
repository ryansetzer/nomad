
# Welcome

${\color{darkslateblue}N}etwork$ ${\color{darkslateblue}O}perations$ ${\color{darkslateblue}M}onitoring$ ${\color{darkslateblue}A}nd$  ${\color{darkslateblue}D}iagnotics$

Nomad is a personal project aimed at creating a versatile, cross-platform solution designed as a networking monitoring tool. Currently in development, the project is primarily written in C++, with plans to expand into front-end development using React and hardware integration.

## Features

- **Core functionality in C++:** Efficient performance and cross-platform compatibility.
- **Modular architecture:** Designed for easy extension, from hardware integration to front-end development.
- **Future integrations:** Planned front-end in React, hardware development, and IO capabilities.

## Hardware
Check out this [link](https://www.circuito.io/app?components=514,11022,11372,11372,11372,164792,299273,466193,860025) for the wiring diagram (done by circuito.io)

## Installation

To get started with Nomad, clone the repository and follow the instructions below.

### Requirements

- C++ compiler (e.g., GCC, Clang, MSVC)
- [Optional: Any specific libraries or dependencies]

### Clone the Repository

```bash
git clone https://github.com/ryansetzer/nomad.git
cd nomad
g++ main.cpp network-check.cpp -o main
./main

