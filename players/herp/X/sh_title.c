static string *eyes = ({
  "(o  )  (o  )",
  "( o )  ( o )",
  "(  o)  (  o)",
  "( o )  ( o )" });

string name;
int i;

start_shadow(u) {
    name=u->query_real_name();
    shadow(u,1);
}

unshadow() { destruct(this_object()); }

string query_presentation() {
string pr;
    pr="The "+capitalize(name)+" is watching you     "+eyes[i++];
    if (i>sizeof(eyes)-1) i=0;
    return pr;
}
