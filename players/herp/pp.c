id(str) { return str=="pp"; }
short() { return "pp"; }
long() { write(short()+".\n"); }
init() { add_action("pp","pp"); }
pp() {
 object *u,ob;
 int i,j,c,a;
 string *sa,s,rn;

 u=users();
 c=sizeof(u);
 a=c;
 for (i=0;i<c;i++) {
  printf("%-17s",query_ip_number(u[i]));
  if ((j=u[i]->query_level())<99) printf("(%2i)",j);
  else printf("%4i",j);
  if (!(rn=u[i]->query_real_name())) s="Logon";
  else s=capitalize(rn);
  if (u[i]->query_invis()) s="("+s+")";
  printf(" %-12s",s);
  printf("%3i D",u[i]->query_age()/43200);
  if ((j=query_idle(u[i]))>117) {
     printf("%4i:%'0'2i",j/60,j%60);
     a--;
  }
  else printf(" active");
  if (!(ob=environment(u[i]))) s="at login";
  else {
    s=file_name(ob);
    if (s=="players/"+rn+"/workroom") s="*";
    else {
      sa=explode(s,"/");
      if (sa[0]=="players")
	 if (sa[1]==rn) {
	    sa[0]=0;
	    sa[1]="&";
	 }
	 else sa[0]="~";
      s=implode(sa,"/");
    }
  }
  printf(" %s\n",s);
 }
 printf("%'-'14 i players (%i active) %'-'38s ---\n",c,a," "+query_load_average());
 return 1;
}
