#include "packets.h"

Packets::Packets(QObject *parent) :
    QObject(parent),
    m_datastream()
{
}

Packets::Packets(QIODevice *d, QObject *parent) :
    QObject(parent),
    m_datastream(d)
{
}

Packets::Packets(QByteArray *a, QIODevice::OpenMode flags, QObject *parent) :
    QObject(parent),
    m_datastream(a, flags)
{
}

Packets::~Packets()
{
}

/* start and end bytes, as well as escape bytes removed */
void Packets::parsePacket(quint8 size)
{
    /* datastream head at CRC */
    /* @parse_packets */

        // error handling
}

quint16 Packets::crc(void *data, int size, quint16 initial)
{
    quint16 remainder = initial;
    quint8 *bytes = reinterpret_cast<quint8 *>(data);
    for (int i = 0; i < size; i++){
        remainder ^= bytes[i] << 8;
        for (int bit = 8; bit > 0; bit--){
            if (remainder & 0x8000){
                remainder = (remainder << 1) ^ 0x1021;
            } else {
                remainder = (remainder << 1);
            }
        }
    }
    return remainder;
}

/* @write_slots_source */


/* @read_slots_source */