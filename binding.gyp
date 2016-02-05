{
  "targets": [
    {
      "target_name": "utilities",
      "type": "static_library",
      "include_dirs": ["dependencies/interfaces"],
      "sources": [ "utilities.cc"],
      "include_dirs": ["dependencies/interfaces","dependencies/xms/lib64","dependencies/xms/cpp/include","dependencies/xms/c/include","dependencies/xms/common"]
    },
    {
      "target_name": "xmsbridge",
      "sources": ["dependencies/xms/common/helperfunctions.c", "XmsBridge.cc","utilities.cc","dependencies/xms/common/helperfunctions.c","MessageListener.cpp","ExceptionListener.cpp"],
      "include_dirs": ["dependencies/interfaces","dependencies/xms/lib64","dependencies/xms/cpp/include","dependencies/xms/c/include","dependencies/xms/common","<!(node -e \"require('nan')\")"],
      "dependencies": ["utilities"],
      "libraries": ["../gxi.lib","../gxi01vn.lib"]
    },
    {
      "target_name": "xmsbridgeAsync",
      "sources": ["XmsBridgeAsync.cc"],
      "include_dirs": ["dependencies/interfaces","dependencies/xms/lib64","dependencies/xms/cpp/include","dependencies/xms/c/include","dependencies/xms/common","<!(node -e \"require('nan')\")"],
      "libraries": ["../gxi.lib","../gxi01vn.lib"]
    }
  ]
}