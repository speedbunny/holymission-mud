/* Entirely updated by Ethereal Cashimor, 230493 */

inherit "obj/thing";

reset(arg) {
int number;

  ::reset(arg);
  if(!arg) {
    set_name("newspaper");
    set_short("A newspaper");
    set_long("This is a newspaper, there's something written on it.\n");
    set_weight(1);
    set_value(5);
    number="players/cashimor/workroom"->query_newspaper();
    set_read_file(sprintf("/players/cashimor/News/%d",number));
  }
}





