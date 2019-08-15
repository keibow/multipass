/*
 * Copyright (C) 2017-2019 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef MULTIPASS_STUB_VIRTUAL_MACHINE_FACTORY_H
#define MULTIPASS_STUB_VIRTUAL_MACHINE_FACTORY_H

#include "stub_virtual_machine.h"

#include <multipass/virtual_machine_factory.h>

namespace multipass
{
namespace test
{
struct StubVirtualMachineFactory : public multipass::VirtualMachineFactory
{
    multipass::VirtualMachine::UPtr create_virtual_machine(const multipass::VirtualMachineDescription&,
                                                           multipass::VMStatusMonitor&) override
    {
        return std::make_unique<StubVirtualMachine>();
    }

    void remove_resources_for(const std::string& name) override
    {
    }

    multipass::FetchType fetch_type() override
    {
        return multipass::FetchType::ImageOnly;
    }

    multipass::VMImage prepare_source_image(const multipass::VMImage& source_image) override
    {
        return source_image;
    }

    void prepare_instance_image(const multipass::VMImage& instance_image,
                                const multipass::VirtualMachineDescription& vm_desc) override
    {
    }

    void configure(const std::string&, YAML::Node&, YAML::Node&) override
    {
    }

    void hypervisor_health_check() override
    {
    }

    QString get_backend_directory_name() override
    {
        return {};
    }

    QString get_backend_version_string() override
    {
        return "stub-5678";
    }
};
}
}

#endif // MULTIPASS_STUB_VIRTUAL_MACHINE_FACTORY_H
