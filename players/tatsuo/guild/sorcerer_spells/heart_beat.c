int id(string arg) 
{
    return (arg == "heart_beat");
}
 void init()
{
   call_out("dest_me",2);
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
