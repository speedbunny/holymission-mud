
int get()
{
    return 1;
}

void init()
{
 object tp;

  tp = environment();
  call_out("guild_set",0,tp);
}
void guild_set(object ob)
{
  ob->set_guild(0);
  destruct(this_object());
}
