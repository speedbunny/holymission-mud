/* my very special short */
object owner;
string new_short;

start_shadow(ob) {
  owner=ob;
  shadow(ob,1);
}

set_short(string str) { if (str) new_short=str; }

query_name() { return new_short; }
/* query_real_name() {return "A masked man";} */

query_presentation() { return new_short; }

short() { return new_short; }

/*
short() {
    return new_short;
string sh;
  if (sh=owner->short()) {

}

*/
