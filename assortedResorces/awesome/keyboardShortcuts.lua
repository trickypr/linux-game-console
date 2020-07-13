local gears = require("gears")
local awful = require("awful")
require("awful.autofocus")
-- Widget and layout library
local wibox = require("wibox")
-- Theme handling library
local beautiful = require("beautiful")
-- Notification library
local naughty = require("naughty")
local menubar = require("menubar")
local hotkeys_popup = require("awful.hotkeys_popup")
-- Enable hotkeys help widget for VIM and other apps

local config = require("config")

modkey = config.modkey

local keyboardShortcuts = {}

keyboardShortcuts.globalKeys = gears.table.join(
  -- Show keyboard shortcut help
  awful.key(
    { modkey,}, 
    "h",      
    hotkeys_popup.show_help,
    { description="show help", group="awesome" }
  ),

  -- You can switch through desktops with
  awful.key(
    { modkey, }, 
    "Tab",
    awful.tag.viewprev,
    { description = "view previous", group = "tag" }
  ),
  awful.key(
    { modkey, "Shift" }, 
    "Tab",  
    awful.tag.viewnext,
    {description = "view next", group = "tag"}
  ),
  
  -- Switch between active windows
  awful.key(
    { "Alt",}, 
    "Tab",
    function ()
        awful.client.focus.byidx( 1)
    end,
    {description = "focus next by index", group = "client"}
  ),
  awful.key(
    { "Alt",}, 
    "Tab",
    function ()
        awful.client.focus.byidx(-1)
    end,
    { description = "focus previous by index", group = "client" }
  ),

  -- Swap between layouts
  awful.key(
    { modkey, }, 
    "space", 
    function () awful.layout.inc(1) end,
    {description = "select next", group = "layout"}
  ),
  awful.key(
    { modkey, "Shift" }, 
    "space", 
    function () awful.layout.inc(-1) end,
    {description = "select previous", group = "layout"}
  ),

  -- Prompt
  awful.key(
    { modkey },
    "r",
    function () awful.screen.focused().mypromptbox:run() end,
    {description = "run prompt", group = "launcher"}
  ),

  -- Menubar
  awful.key(
    { modkey }, 
    "p", 
    function() menubar.show() end,
    {description = "show the menubar", group = "launcher"}
  )
)

keyboardShortcuts.clientKeys = gears.table.join(
  -- Toggle app fullscreen  
  awful.key(
    { modkey, }, 
    "f",
    function (c)
        c.fullscreen = not c.fullscreen
        c:raise()
    end,
    {description = "toggle fullscreen", group = "client"}
  ),

  -- Close windows
  awful.key(
    { modkey }, 
    "w",
    function (c) c:kill() end,
    {description = "close", group = "client"}
  )
)

return keyboardShortcuts
