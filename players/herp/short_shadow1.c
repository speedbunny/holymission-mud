/* my very special short */

string *ldesc = ({"  (o  )   (o  )",
		  "  ( o )   ( o )",
		  "  (  o)   (  o)",
		  "  (  0)   (  0)",
		  "  ( 0 )   ( 0 )",
		  "  (0  )   (0  )" });
int i=0;
object owner;

start_shadow(ob) {
  owner=ob;
  shadow(ob,1);
}

short() {
string sh;
  if (sh=owner->short()) {
	i%=sizeof(ldesc);
	sh="                          ~~~      ~~~\n       "+sh+ldesc[i++];
	return sh;
  }
}
