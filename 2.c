#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MSG_SIZE 100

struct msg_buffer {
    long msg_type;
    char msg_text[MSG_SIZE];
};

int main() {
    key_t key = ftok("progfile", 65); // используем тот же ключ
    int msgid = msgget(key, 0666 | IPC_CREAT); // получаем очередь сообщений

    struct msg_buffer message;

    // Читаем 5 сообщений
    for (int i = 0; i < 5; i++) {
        msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);
        printf("Reader: Received: %s\n", message.msg_text);
    }

    // Пишем 5 сообщений
    for (int i = 0; i < 5; i++) {
        message.msg_type = 1; // тип сообщения
        sprintf(message.msg_text, "Response %d", i + 1);
        msgsnd(msgid, &message, sizeof(message.msg_text), 0);
        printf("Reader: Sent: %s\n", message.msg_text);
        sleep(1); // Задержка для наглядности
    }

    return 0;
}
