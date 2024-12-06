#include "request.h"
int parse_request(char *reqbuf)
{
    struct req_tlv_header_t *h = (struct req_tlv_header_t *)reqbuf;

    if (h->magic != 0x4545)
    {
        printf("BAD magic\n");
        return -1;
    }
    char *data = (char *)(&h[1]);

    switch (h->type)
    {
    case REQ_HELLO:
        printf("Got HELLO\n");
        break;
    case REQ_GOODBYE:
        printf("Got GOODBYE\n");
        break;
    case REQ_MESSAGE:
        printf("Got MSG\n");
        parse_msg(h, data);
        break;
    default:
        printf("Unknown message type\n");
        return -1;
        break;
    }
    return 0;
}

int parse_msg(struct req_tlv_header_t *h, char *data)
{
    char msgbuf[64];
    printf("Copying data for processing\n");
    memcpy(msgbuf, data, h->len);
    return 0;
}

