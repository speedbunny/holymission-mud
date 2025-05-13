id(str) { return str=="rus"; }
short() { return "a rus"; }
long() { write(short()+".\n"); }
init() { add_action("rus","rus"); }
get() { return 1; }
rus() {
string *rdesc,*rms;
int *r;
int i,j;

  rdesc=({
	"utime: user time used  ",
	"stime: system time used",
	"maxrss: maximum resident set size",
	"rus.ru_ixrss:  (currently 0)",
	"rus.ru_idrss:   integral resident set size",
	"rus.ru_isrss:  (currently 0)",
	"rus.ru_minflt:  page faults not requiring physical I/O",
	"rus.ru_majflt:  page faults requiring physical I/O",
	"rus.ru_nswap:   swaps",
	"rus.ru_inblock: block input operations",
	"rus.ru_oublock: block output operations",
	"rus.ru_msgsnd: messages sent",
	"rus.ru_msgrcv: messages received",
	"rus.ru_nsignals: signals received",
	"rus.ru_nvcsw: voluntary context switches",
	"rus.ru_nivcsw: involuntarty context switches" });

  rms=({
	"                                  _3",
	"10 seconds",
	"    seconds",
	"Kbytes",
	"?",
	"bytes",
	"?",
	" ", " ", " "," "," "," "," "," "," "," " });

  r=rusage();
  r[2]/=1024;
  write(rms[0]+"\n");
  for(i=0;i<16;i++)
     write(rdesc[i]+" "+r[i]+" "+rms[i+1]+"\n");
  i=r[0]/1000+r[1]/1000;
  j=i / 60;
  


  return 1;
}
