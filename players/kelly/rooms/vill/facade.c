/* FACADE.C - Programmed by Kelly */
/* 090793: Ethereal Cashimor: Exit incoorperated in mudlib and removed */

inherit "obj/thing";

reset(arg) {
  if(!arg) {
    set_name("sign");
    set_short("A wooden sign"),
    set_long("A sign made of wood. There is something written on it.\n");
    set_can_get(0);
    set_read("The new opened street to Red-Rock-Junction.\n");
  }
}
