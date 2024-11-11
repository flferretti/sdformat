# Copyright (C) 2022 Open Source Robotics Foundation

# Licensed under the Apache License, Version 2.0 (the "License")
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at

#       http://www.apache.org/licenses/LICENSE-2.0

# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import unittest
from gz_test_deps.sdformat import URDF2SDF, ParserConfig
import tinyxml2


class TestURDF2SDF(unittest.TestCase):

    def test_convert_urdf_string_to_sdf(self):
        urdfStr = """
        <robot name="test_robot">
            <link name="link1">
                <inertial>
                    <mass value="1.0"/>
                    <origin rpy="0 0 0" xyz="0 0 0"/>
                    <inertia ixx="1.0" ixy="0.0" ixz="0.0" iyy="1.0" iyz="0.0" izz="1.0"/>
                </inertial>
            </link>
        </robot>"""

        config = ParserConfig()
        sdfXmlDoc = tinyxml2.XMLDocument()
        urdf2sdf = URDF2SDF()
        urdf2sdf.InitModelString(urdfStr, config, sdfXmlDoc)

        printer = tinyxml2.XMLPrinter()
        sdfXmlDoc.Print(printer)
        sdfStr = printer.CStr()

        self.assertIn('<model name="test_robot">', sdfStr)
        self.assertIn('<link name="link1">', sdfStr)
        self.assertIn("<inertial>", sdfStr)
        self.assertIn("<mass>1</mass>", sdfStr)
        self.assertIn("<inertia>", sdfStr)


if __name__ == "__main__":
    unittest.main()
