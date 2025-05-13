#include "/sys/defs.h"

int main(string str) {

  mapping imp_hosts;
  mixed *host;
  string s;

  if (str) {
    if (!(host=master_object()->query_imp_hosts()[str])) {
      notify_fail("No such peer.\n");
      return 0;
    }
    printf("Name:      %s\n",str);
    printf("Host:      %s\n",host[4]);
    printf("IP:        %s\n",host[0]);
    if (host[5]==-1) {
      printf("NEVER ACCESSED\n");
      return 1;
    }
    printf("Mud-Port:  %d\n",host[5]);
    printf("imp-Port:  %d\n",host[1]);
    printf("GameDrvr:  %s\n",((s=host[2])?s:"N/A"));
    printf("Mudlib:    %s\n",((s=host[3])?s:"N/A"));
    printf("Last acc:  %s\n",((s=host[6])?s:"N/A"));
    return 1;
  }

  return 1;
}

