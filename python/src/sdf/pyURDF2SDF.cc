/*
 * Copyright (C) 2022 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "pyURDF2SDF.hh"

using namespace pybind11::literals;

namespace sdf
{
inline namespace SDF_VERSION_NAMESPACE {
namespace python
{
void defineURDF2SDF(pybind11::object module)
{
  pybind11::class_<sdf::URDF2SDF>(module, "URDF2SDF")
    .def(pybind11::init<>())
    .def("InitModelDoc", &sdf::URDF2SDF::InitModelDoc)
    .def("InitModelFile", &sdf::URDF2SDF::InitModelFile)
    .def("InitModelString", &sdf::URDF2SDF::InitModelString)
    .def_static("IsURDF", &sdf::URDF2SDF::IsURDF)
    .def("ListSDFExtensions", pybind11::overload_cast<>(&sdf::URDF2SDF::ListSDFExtensions))
    .def("ListSDFExtensions", pybind11::overload_cast<const std::string&>(&sdf::URDF2SDF::ListSDFExtensions));
}
}  // namespace python
}  // namespace SDF_VERSION_NAMESPACE
}  // namespace sdf