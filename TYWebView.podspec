Pod::Spec.new do |s|

# ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
s.name         = "TYWebView"
s.version      = "1.0.0"
s.summary      = "TYWebView"
s.description  = <<-DESC
               TYWebView
               DESC
s.homepage     = "https://github.com/HangzhouSunline/TYWebView"
s.license      = { :type => "MIT"}
s.author             = { "yangxuran" => "yangxuran@sunline.cn" }
s.ios.deployment_target = "9.0"
s.source       = { :git => "https://github.com/HangzhouSunline/TYWebView.git", :tag => "#{s.version}" }


s.vendored_frameworks = 'TYWebView.framework'
s.frameworks = "UIKit", "Foundation"
s.dependency 'openssl', '~>1.0'

end

