inherit "obj/weapon";
reset(arg)
{
  ::reset(arg);
  if(arg) return 1;
  set_weight(1);
  set_class(12);
  set_value(500);
  set_name("dagger");
  set_short("A long dagger");
  set_long("A long, sharp dagger.\n");
}
extra_look()
{
  if(this_object()->query_wielded())
  {
    return capitalize(wielded_by->query_pronoun()) + " is turning a deep red!";
  }
}
wield(str)
{
  ::wield(str);
  if(id(str))
  {
    write("Your blood rushes to the surface of your skin as you turn the\n" +
          "reddish color of the nordel!\n");
    return 1;
  }
}
