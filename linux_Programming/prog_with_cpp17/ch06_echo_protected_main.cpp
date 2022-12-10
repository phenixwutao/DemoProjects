int main(int argc, char** argv)
{
  try {
    return protected_main(argc, argv);
  }
  catch(const std::exception& e)
    {
      std::cerr << "Caught unknown exception:\n" ;
      std::cerr << "- what: " << e.what() << '\n';      
    }
  catch(...)
    {
      std::cerr << "Caught unknown exception\n" ;
    }
  
  return EXIT_FAILURE;
}
