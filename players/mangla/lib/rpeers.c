#include "/sys/defs.h"

int main(string str) {

  mapping imp_hosts;
  mixed *mi,*mv;
  int i;

  if (str) return 0;
  if (!(imp_hosts=master_object()->query_imp_hosts())) {
    notify_fail("No known imp-hosts.\n");
    return 0;
  }
  mi=m_indices(imp_hosts);
  mv=m_values(imp_hosts);

  for (i=0;i<sizeof(imp_hosts);i++) {
    printf("%-15s %-15s", mi[i],mv[i][0]);
    if (mv[i][5]==-1)
      printf(" NEVER ACCESSED\n");
    else
      printf(" %4d (%s)\n",mv[i][5],mv[i][4]);
  }

  return 1;
}

