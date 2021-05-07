/**
 ============================================================================
 @brief			MqttClientExample.c
 @author		Leandro Daniel Huff
 @version		1.0.0
 @copyright		Not copyrithed, it's free for use without any warrant.
 @description   MQTT client example in C, Ansi-style  .
 ============================================================================
 */

/*
 * Includes
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <MQTTClient.h>

/*
 * Defines
 */

/* Set MQTT client to a local TCP broker server,
 * If need to use another MQTT broker,
 * Change this MQTT address and protocol
 */
#define MQTT_ADDRESS   "tcp://127.0.0.1"

/* Set unique app client ID */
#define CLIENTID       "MQTTCClientID"

/* Set publish and subscribe topics to send and receive message respectively */
#define MQTT_PUBLISH_TOPIC     "MQTTCClientPubTopic"
#define MQTT_SUBSCRIBE_TOPIC   "MQTTCClientSubTopic"

/*
 *  Global variables
 */
MQTTClient client;

/*
 * Function prototypes
 */
void publish(MQTTClient client, char *topic, char *payload);
int on_message(void *context, char *topicName, int topicLen, MQTTClient_message *message);

/*
 * Implementation
 */

/* @brief 			Publicacao de mensagens MQTT
 * @param	client	Client MQTT
 * @param	topic	Topic MQTT
 * @param	payload	Data payload
 * @return	nothing
 */
void publish(MQTTClient client, char *topic, char *payload)
{
	MQTTClient_message pubmsg = MQTTClient_message_initializer;

	pubmsg.payload = payload;
	pubmsg.payloadlen = strlen(pubmsg.payload);
	pubmsg.qos = 2;
	pubmsg.retained = 0;
	MQTTClient_deliveryToken token = 0;
	MQTTClient_publishMessage(client, topic, &pubmsg, &token);
	MQTTClient_waitForCompletion(client, token, 10UL);
}

/* @brief				Callback function for received MQTT messages and send it back to MQTT broker.
 * @param	context		Context of message
 * @param	topicname	Pointer to topic name
 * @param	topicLen	Size of message
 * @param	message		Pointer to message
 * @return 	1			Successful, this example doesn't treat any error. :|
 */
int on_message(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
	static unsigned int count_messages = 0;
	char *payload = message->payload;

	/*Show message arrived */
	count_messages++;
	printf("Message (%u) arrived!    Topic: %s    Message: %s\n", count_messages, topicName, payload);

	/* Resend the same received message (echo) */
	publish(client, MQTT_PUBLISH_TOPIC, payload);

	MQTTClient_freeMessage(&message);
	MQTTClient_free(topicName);
	return 1;
}

int main(int argc, char *argv[])
{
	int rc;
	MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;

	/* Init MQTT (connection and subscribes) */
	MQTTClient_create(&client, MQTT_ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
	MQTTClient_setCallbacks(client, NULL, NULL, on_message, NULL);

	rc = MQTTClient_connect(client, &conn_opts);

	if (rc != MQTTCLIENT_SUCCESS) {
		printf("\nConnect to MQTT broker failed! Error: %d\n", rc);
		exit(-1);
	}

	MQTTClient_subscribe(client, MQTT_SUBSCRIBE_TOPIC, 0);

	while (1)
	{
		/*
		 * This application run as an "interrupt" treater on a callback function MQTT message.
		 * Therefore, this main application looping do nothing.
		 * To exit from the application,
		 * just press and retain keyboard keys CTRL and C and release them.
		 */
	}
}
