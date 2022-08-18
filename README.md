# dhtexporter
Prometheus exporter to export dht11 temperature + humidity sensor data to prometheus
This is to be used on an ESP8266 but I am sure you can run it on other boards with slight modification


## Installation and Usage

1. [Add ESP8266 To Board Manager](https://arduino-esp8266.readthedocs.io/en/latest/installing.html#:~:text=Open%20Boards%20Manager%20from%20Tools,Tools%20%3E%20Board%20menu%20after%20installation.)
2. Select board
3. Upload Code
4. Add server to prometheus (add in targets parameter) 


### Metrics

Server Is Defaulted At http://IP:8663/metrics


       Name         | Description
--------------------|------------
dhtexp_temperature    show temperature reading in celcius
dhtexp_humidit        show humidity level reading


