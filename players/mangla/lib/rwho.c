#include "/sys/defs.h"

int main(string str) {

  mapping imp_hosts;
  mixed *mi;
  int i;

  if (!(imp_hosts=master_object()->query_imp_hosts())) {
    notify_fail("No known imp-hosts.\n");
    return 0;
  }
  if (str=="*") {
    mi=m_indices(imp_hosts);
    for (i=0;i<sizeof(mi);i++) master_object()->send_rwho_q(mi[i]);
    write("Ok.\n");
    return 1;
  }
  else if (imp_hosts[str]) {
    master_object()->send_rwho_q(str);
    write("Ok.\n");
    return 1;
  }

  return 1;
}

