inherit "/obj/thing";

object home;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("sphinx_object");
    set_weight(2);
    home = 0;
  } else {
    object env;
    env = environment(this_object());
    if (!((home && (home == env)) || environment(env)))
      destruct(this_object());
  }
}

query_sphinx() {return 1;}

config (version,h) {
  string *str;
  int i;
  str=({"broom","skull","horseshoe","map","bellows"});

  i = (stringp(version))? member_array(version,str) : version;
  if (i<0)i=random(sizeof(str));

  set_name(str[i]);
  set_short("A " + str[i]);

  str=({"This broom has swept its fair share of floors.\n"
          +"It looks like a convertible for a witch.\n",
        "It's a skull. Fortunately it doesn't belong to anyone you know.\n",
        "This horseshoe seems to have taken quite a beating.\n",
        "This fine map of the land of druid Lakmir is quite detailed,\n"
          +"although incomplete.\n",
        "This wooden bellows has stoked many a floundering fire.\n"
        });
  set_long(str[i]);
  if (h) home=h;
  return this_object();
}
