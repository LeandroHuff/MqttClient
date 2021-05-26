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
