
int satha(string arg)
{

object shd;

    if (this_player()->query_religion()!="Quercus") return 0;
    if (arg!="quercus")
    {
       write("Quercus sniffs sadly at you.\n");
       return 1;
    }
    if (this_player()->query_real_name()=="sungold" ||
        this_player()->query_real_name()=="goldsun"){

//    shd=clone_object("players/goldsun/religion/relig_shad");
//    shd->start_shadow(this_player(),0,"relig_shad");
    write("You leave your body.\n");
    shd=clone_object("players/goldsun/religion/meditator");
    move_object(shd,this_player());
    shd->set_seek(this_player());
    return 1; }
  write("Not worked yet.\nTry a week later.\n");
  return 1;
}


