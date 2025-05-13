#include "/sys/defs.h"

int main(string str) {

  string ipnum,pp;
  int port_udp;

  if (!str || sscanf(str,"%s %s",ipnum,pp)!=2 || !(port_udp=to_int(pp))) {
    notify_fail("rping <ip> <port>\n");
    return 0;
  }
  master_object()->send_ping_q(ipnum,port_udp);
  write("Ok.\n");

  return 1;
}

