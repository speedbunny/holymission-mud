int id(string arg) 
{
    return (arg == "poser");
}
 void init()
{
   call_out("dest_me",250);
}

void dest_me()
{
   destruct(this_object());
}

int get()
{
    return 1;
}

int drop()
{
    return 0;
}

