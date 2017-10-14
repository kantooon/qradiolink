#ifndef NETDEVICE_H
#define NETDEVICE_H

#include <QObject>
#include <QDebug>
#include <QCoreApplication>
#include <unistd.h>
#include <math.h>
#include <sys/socket.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <fcntl.h>

class NetDevice : public QObject
{
    Q_OBJECT
public:
    explicit NetDevice(QObject *parent = 0);

signals:

public slots:

public:
    unsigned char* read_buffered(int &bytes);

private:
    int tun_init();
    int _fd_tun;

};

#endif // NETDEVICE_H