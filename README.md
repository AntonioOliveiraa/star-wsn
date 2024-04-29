# Wireless Sensor Network in Star Topology Without Internet Access

A wireless sensor network with ESP32s has been implemented in a star topology for sensor data collection. These data are visualized on a dashboard hosted by a local web server without internet access.

## Starting

To clone and run this project locally, follow these standard GitHub steps:

```bash
git clone https://github.com/AntonioOliveiraa/star-wsn.git
cd star-wsn
```
Or
```bash
gh repo clone AntonioOliveiraa/star-wsn
```
### Prerequisites

- [PlatformIO IDE](https://platformio.org/platformio-ide) for VS Code.

### Installation and Configuration

Install the PlatformIO extension in VS Code and follow the instructions to set up your development environment. Follow the [platformio.ini](https://github.com/AntonioOliveiraa/star-wsn/blob/main/platformio.ini) file to configure the project.

## Project Structure

The project consists of a master node and three slave nodes. The slave nodes collect data from the DS18B20 sensors and send it to the master node via TCP/IP.

### Materials Used

- 4x ESP32 Doit Devkit v1
- 3x DS18B20 temperature sensors
- 3x 4.7 KOhm resistors

## Dashboard

The dashboard is hosted locally by a web server and displays the collected data in graphs, using the Highcharts.js library in offline mode.

### Date Folder

Contains the HTML and highcharts.js files for data visualization. The files must be loaded into the microcontroller's flash memory to be used.

## License

This project is licensed under the MIT License - see the file [LICENSE.md](https://github.com/AntonioOliveiraa/star-wsn/blob/main/LICENSE.md) for details.

## Contributing

Please read [CONTRIBUTING.md](https://github.com/AntonioOliveiraa/star-wsn/blob/main/CONTRIBUTING.md) for details about our code of conduct and the process for submitting pull requests.

## Authors

* **Antônio Oliveira** - *Main Developer* - [AntonioOliveiraa](https://github.com/AntonioOliveiraa)
* **Gustavo Marques** - *Developer* - [GMFK00](https://github.com/gmfk00)
* **José Muniz** - *Developer* - [joseribacermuniz](https://github.com/joseribacermuniz)
* **Paulo Fernandes** - *Analyst* - [pfs1224](https://github.com/pfs1224)

See also the list of [collaborators](https://github.com/AntonioOliveiraa/star-wsn/graphs/contributors) who participated in this project.

## Thanks

* Special thanks to everyone who contributed code and ideas.
* To Professor Paulo Fernandes for the requirements and initial ideas for the project.