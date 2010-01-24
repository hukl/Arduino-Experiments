#!/usr/bin/ruby

require 'rubygems'
require 'serialport'
require 'osx/cocoa'

include OSX
OSX.require_framework 'ScriptingBridge'


def set_volume volume
  itunes = SBApplication.applicationWithBundleIdentifier_("com.apple.iTunes")
  itunes.soundVolume = volume
end

SerialPort.open("/dev/tty.usbserial-A900abY5", 9600) do |sp|
  
  volume = 0
  
  loop do
    sp.gets
    current_volume = ((sp.gets.to_f / 1023) * 100).to_i
    
    if current_volume != volume
      volume = current_volume
      set_volume(volume)
    end
    
    sp.flush
    sleep(0.01)
  end
  
end