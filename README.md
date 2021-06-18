# MqttClient

Simple PAHO MQTT client example, it immplement an MQTT protocol subscribe/publish
with minimal code to show how it works, the exemple use a TCP addres for local host as
127.0.0.1 and an ID, while running, every messages sent to a specific topic will be
echoed to another topic to demonstrate that the MQTT broker and protocol are running well.
For this example, I used MQTT X, it is a Cross-platform MQTT 5.0 Desktop Client, others MQTT
clients could be used as:

  * MQTT X        (https://mqttx.app/)
  * MQTT Explorer (http://mqtt-explorer.com/)
  * MQTT Spy      (https://github.com/eclipse/paho.mqtt-spy)

As it run on Linux, before run the exemple, I've had install a MQTT server, I choose the
Mosquito MQTT broker server running as a local broker into Linux operating system, all
connection was made local, for external connection it should be pointed to another TCP
address and an encrypted protocol could be aplyied as a protected layer. Otherwise, it was
an exciting exercise and an small example as an startup for new projects and challenges with
MQTT protocols. I hoppe you enjoy it, learn and use it freely, contributes to iimprove this
code will be nice.

This example is a contribution from Embarcados (https://www.embarcados.com.br) and this article was published in https://www.embarcados.com.br/paho-mqtt-em-c-no-linux-embarcado/ by Pedro Bertoleti (http://pedrobertoleti.com.br/), some comments and code was added to adjust the example to my specific environment setup.


More information about MQTT Protocol and IoT can be viewed at:

https://www.embarcados.com.br/paho-mqtt-em-c-no-linux-embarcado/<br>
https://www.embarcados.com.br/o-mqtt-como-ipc-em-sistemas-linux/<br>
https://www.embarcados.com.br/protocolo-mqtt-a-solucao-para-m2m/<br>
https://www.embarcados.com.br/mqtt-na-raspberry-pi-com-node-red/<br>
https://www.embarcados.com.br/webinar-renesas-aplicacao-mqtt-tago-io/<br>
https://www.embarcados.com.br/mqtt-sn-mqtt-para-rede-de-sensores/<br>
https://www.embarcados.com.br/mqtt-sn-mqtt-para-rede-de-sensores/<br>
https://www.embarcados.com.br/mqtt-dash/<br>
https://www.embarcados.com.br/conectando-devicehub-com-nodemcu-e-mqtt/<br>
https://www.embarcados.com.br/conectando-devicehub-com-nodemcu-e-mqtt/<br>
https://www.embarcados.com.br/mqtt-e-intel-edison/<br>
https://www.embarcados.com.br/mqtt-protocolos-para-iot/<br>
