/*
 * #%L
 * OME-QTWIDGETS C++ library for display of OME-Files pixel data and metadata.
 * %%
 * Copyright © 2016 Open Microscopy Environment:
 *   - Massachusetts Institute of Technology
 *   - National Institutes of Health
 *   - University of Dundee
 *   - Board of Regents of the University of Wisconsin-Madison
 *   - Glencoe Software, Inc.
 * %%
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are
 * those of the authors and should not be interpreted as representing official
 * policies, either expressed or implied, of any organization.
 * #L%
 */

#include <ome/qtwidgets/config-internal.h>

#define OME_COMMON_MODULE_INTROSPECTION 1
#include <ome/common/module.h>
#include <ome/xml/module.h>
#include <ome/files/module.h>
#include <ome/qtwidgets/module.h>

namespace
{
  using ome::common::RegisterModule;

  void register_paths()
  {
    // OME-QtWidgets package-specific paths.
    static RegisterModule ome_qtwidgets_data
      ("ome-qtwidgets-data",
       "OME_QTWIDGETS_PKGDATADIR",
       "OME_QTWIDGETS_HOME",
       "OME_HOME",
       OME_QTWIDGETS_INSTALL_FULL_PKGDATADIR,
       OME_QTWIDGETS_INSTALL_PKGDATADIR,
       OME_QTWIDGETS_INSTALL_PREFIX,
       OME_QTWIDGETS_SHLIBDIR,
       module_path);

    static RegisterModule ome_qtwidgets_icon
      ("ome-qtwidgets-icon",
       "OME_QTWIDGETS_ICONDIR",
       "OME_QTWIDGETS_HOME",
       "OME_HOME",
       OME_QTWIDGETS_INSTALL_FULL_ICONDIR,
       OME_QTWIDGETS_INSTALL_ICONDIR,
       OME_QTWIDGETS_INSTALL_PREFIX,
       OME_QTWIDGETS_SHLIBDIR,
       module_path);

    static RegisterModule ome_qtwidgets_libexec
      ("ome-qtwidgets-libexec",
       "OME_QTWIDGETS_PKGLIBEXECDIR",
       "OME_QTWIDGETS_HOME",
       "OME_HOME",
       OME_QTWIDGETS_INSTALL_FULL_PKGLIBEXECDIR,
       OME_QTWIDGETS_INSTALL_PKGLIBEXECDIR,
       OME_QTWIDGETS_INSTALL_PREFIX,
       OME_QTWIDGETS_SHLIBDIR,
       module_path);
  }

  struct AutoRegister
  {
    AutoRegister()
    {
      register_paths();
    }
  };

  AutoRegister path_register;

}

namespace ome
{
  namespace qtwidgets
  {

    void
    register_module_paths()
    {
      ome::common::register_module_paths();
      ome::xml::register_module_paths();
      register_paths();
    }

  }
}
