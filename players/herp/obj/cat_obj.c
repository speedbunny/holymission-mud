id(str) { if (str=="cat") return 1; }

init() { add_action("cat_file","cat"); }

cat_file(path)
{
    if (!path)
        return 0;
         if (!cat(path))
        write("No such file.\n");
    destruct(this_object());
    return 1;
}


