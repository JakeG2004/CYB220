#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h> // For htons/ntohs if required
enum REQ_TYPE
{
    REQ_HELLO,
    REQ_GOODBYE,
    REQ_MESSAGE,
};

struct req_tlv_header_t
{
    short magic;
    char type;
    short len;
} __attribute__((__packed__));

int parse_msg(struct req_tlv_header_t *h, char *data);

int parse_request(char *reqbuf);