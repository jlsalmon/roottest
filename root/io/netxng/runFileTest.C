Int_t runFileTest()
{
  gDebug = 0;

  // Open()
  TFile *f = TFile::Open( "root://valtical08.cern.ch//localdisk/xrootd/test/test1.root" );

  // IsOpen()
  std::cout << "IsOpen: " << ( f->IsOpen() ? "true" : "false" ) << std::endl;

  // GetSize()
  Long64_t size = f->GetSize();
  std::cout << "File size: " << size << std::endl;

  // ReadBuffer(3)
  char *buf = new char[1024];
  if( f->ReadBuffer( buf, 0, 1024 ) )
  {
    std::cout << "Error reading" << std::endl;
    return 1;
  }
  delete buf;

  // Seek()
  f->Seek( 1024, TFile::ERelativeTo::kBeg );

  // ReadBuffer(2)
  buf = new char[1024];
  if( f->ReadBuffer( buf, 1024 ) )
  {
    std::cout << "Error reading" << std::endl;
    return 1;
  }
  delete buf;

  // ReadBuffers()
  buf = new char[4096];
  Long64_t pos[4] = {0, 1024, 2048, 3072};
  Int_t    len[4] = {1024, 1024, 1024, 1024};
  Int_t    nbuf   = 4;

  if( f->ReadBuffers(buf, pos, len, nbuf) )
  {
    std::cout << "Error reading" << std::endl;
    return 1;
  }
  delete buf;

  // ReOpen()
  if( f->ReOpen( "update" ) != 0 )
  {
    std::cout << "Error reopening file in write mode" << endl;
    return 1;
  }

  // WriteBuffer()
  buf = "write me";
  f->Seek( 0, TFile::ERelativeTo::kEnd );

  if( f->WriteBuffer( buf, 8 ) )
  {
    std::cout << "Error writing" << std::endl;
    return 1;
  }

  f->ReOpen( "read" );
  f->Close();
  return 0;
}
