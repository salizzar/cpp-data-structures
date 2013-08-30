# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure('2') do |config|
  config.vm.box = 'debian-wheezy-amd64-base'

  config.vm.provider :virtualbox do |vb|
    vb.customize [ :modifyvm, :id, '--memory', 512 ]
    vb.customize [ :modifyvm, :id, '--cpus',     4 ]
  end

  config.vm.provision :shell, path: 'cookbooks/default'
end
