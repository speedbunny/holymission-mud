 niff(arg)
 {
     if (this_player()->query_religion()!="Urimuri")
    {
        write("Niffing is only allowed when you follow urimuri.\n");
        return 1;
    }
    else if (!arg)
        write("You niff.\n");
    else
        write("You niff "+arg+".\n");
    return 1;
}
