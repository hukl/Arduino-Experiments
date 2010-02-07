#!/usr/local/bin/macruby
framework 'Foundation'
framework 'ScriptingBridge'
require 'serialport'

 
itunes = SBApplication.applicationWithBundleIdentifier("com.apple.itunes")
load_bridge_support_file 'iTunes.bridgesupport'
itunes.run
 
class SBElementArray
  def [](value)
    self.objectWithName(value)
  end
end
 
itunes.stop
itunes.soundVolume = 100