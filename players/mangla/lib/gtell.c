#include "/sys/defs.h"

int main(string str) {

  string wiz,mud,msg;

  if (!str || sscanf(str,"%s@%s %s",wiz,mud,msg)!=3) {
    notify_fail("Usage: gtell wiz@mud message.\n");
    return 0;
  }
  if ((master_object()->send_gtell_w(mud,wiz,msg))<0)
    write("Fail.\n");
  else
    write("Ok.\n");

  return 1;
}

