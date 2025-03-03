/*
 * Copyright 2020 Open Source Robotics Foundation
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
 *
*/
#ifndef SDF_HEIGHTMAP_HH_
#define SDF_HEIGHTMAP_HH_

#include <string>
#include <gz/math/Vector3.hh>
#include <gz/utils/ImplPtr.hh>
#include <sdf/Element.hh>
#include <sdf/Error.hh>
#include <sdf/config.hh>

namespace sdf
{
  // Inline bracket to help doxygen filtering.
  inline namespace SDF_VERSION_NAMESPACE {
  //

  // Forward declarations.
  class ParserConfig;

  /// \brief Texture to be used on heightmaps.
  class SDFORMAT_VISIBLE HeightmapTexture
  {
    /// \brief Constructor
    public: HeightmapTexture();

    /// \brief Load the heightmap texture geometry based on a element pointer.
    /// This is *not* the usual entry point. Typical usage of the SDF DOM is
    /// through the Root object.
    /// \param[in] _sdf The SDF Element pointer
    /// \return Errors, which is a vector of Error objects. Each Error includes
    /// an error code and message. An empty vector indicates no error.
    public: Errors Load(ElementPtr _sdf);

    /// \brief Load the heightmap texture geometry based on a element pointer.
    /// This is *not* the usual entry point. Typical usage of the SDF DOM is
    /// through the Root object.
    /// \param[in] _sdf The SDF Element pointer
    /// \param[in] _config Parser configuration
    /// \return Errors, which is a vector of Error objects. Each Error includes
    /// an error code and message. An empty vector indicates no error.
    public: Errors Load(sdf::ElementPtr _sdf, const ParserConfig &_config);

    /// \brief Get the heightmap texture's size.
    /// \return The size of the heightmap texture in meters.
    public: double Size() const;

    /// \brief Set the size of the texture in meters.
    /// \param[in] _size The size of the texture in meters.
    public: void SetSize(double _size);

    /// \brief Get the heightmap texture's diffuse map.
    /// \return The diffuse map of the heightmap texture.
    public: std::string Diffuse() const;

    /// \brief Set the filename of the diffuse map.
    /// \param[in] _diffuse The diffuse map of the heightmap texture.
    public: void SetDiffuse(const std::string &_diffuse);

    /// \brief Get the heightmap texture's normal map.
    /// \return The normal map of the heightmap texture.
    public: std::string Normal() const;

    /// \brief Set the filename of the normal map.
    /// \param[in] _normal The normal map of the heightmap texture.
    public: void SetNormal(const std::string &_normal);

    /// \brief Get a pointer to the SDF element that was used during load.
    /// \return SDF element pointer. The value will be nullptr if Load has
    /// not been called.
    public: sdf::ElementPtr Element() const;

    /// \brief Private data pointer.
    GZ_UTILS_IMPL_PTR(dataPtr)
  };

  /// \brief Blend information to be used between textures on heightmaps.
  class SDFORMAT_VISIBLE HeightmapBlend
  {
    /// \brief Constructor
    public: HeightmapBlend();

    /// \brief Load the heightmap blend geometry based on a element pointer.
    /// This is *not* the usual entry point. Typical usage of the SDF DOM is
    /// through the Root object.
    /// \param[in] _sdf The SDF Element pointer
    /// \return Errors, which is a vector of Error objects. Each Error includes
    /// an error code and message. An empty vector indicates no error.
    public: Errors Load(ElementPtr _sdf);

    /// \brief Get the heightmap blend's minimum height.
    /// \return The minimum height of the blend layer.
    public: double MinHeight() const;

    /// \brief Set the minimum height of the blend in meters.
    /// \param[in] _uri The minimum height of the blend in meters.
    public: void SetMinHeight(double _minHeight);

    /// \brief Get the heightmap blend's fade distance.
    /// \return The fade distance of the heightmap blend in meters.
    public: double FadeDistance() const;

    /// \brief Set the distance over which the blend occurs.
    /// \param[in] _uri The distance in meters.
    public: void SetFadeDistance(double _fadeDistance);

    /// \brief Get a pointer to the SDF element that was used during load.
    /// \return SDF element pointer. The value will be nullptr if Load has
    /// not been called.
    public: sdf::ElementPtr Element() const;

    /// \brief Private data pointer.
    GZ_UTILS_IMPL_PTR(dataPtr)
  };

  /// \brief Heightmap represents a shape defined by a 2D field, and is usually
  /// accessed through a Geometry.
  class SDFORMAT_VISIBLE Heightmap
  {
    /// \brief Constructor
    public: Heightmap();

    /// \brief Load the heightmap geometry based on a element pointer.
    /// This is *not* the usual entry point. Typical usage of the SDF DOM is
    /// through the Root object.
    /// \param[in] _sdf The SDF Element pointer
    /// \return Errors, which is a vector of Error objects. Each Error includes
    /// an error code and message. An empty vector indicates no error.
    public: Errors Load(ElementPtr _sdf);

    /// \brief Load the heightmap geometry based on a element pointer.
    /// This is *not* the usual entry point. Typical usage of the SDF DOM is
    /// through the Root object.
    /// \param[in] _sdf The SDF Element pointer
    /// \param[in] _config Parser configuration
    /// \return Errors, which is a vector of Error objects. Each Error includes
    /// an error code and message. An empty vector indicates no error.
    public: Errors Load(ElementPtr _sdf, const ParserConfig &_config);

    /// \brief Get the heightmap's URI.
    /// \return The URI of the heightmap data.
    public: std::string Uri() const;

    /// \brief Set the URI to a grayscale image.
    /// \param[in] _uri The URI of the heightmap.
    public: void SetUri(const std::string &_uri);

    /// \brief The path to the file where this element was loaded from.
    /// \return Full path to the file on disk.
    public: const std::string &FilePath() const;

    /// \brief Set the path to the file where this element was loaded from.
    /// \paramp[in] _filePath Full path to the file on disk.
    public: void SetFilePath(const std::string &_filePath);

    /// \brief Get the heightmap's scaling factor.
    /// \return The heightmap's size.
    public: gz::math::Vector3d Size() const;

    /// \brief Set the heightmap's scaling factor. Defaults to 1x1x1.
    /// \return The heightmap's size factor.
    public: void SetSize(const gz::math::Vector3d &_size);

    /// \brief Get the heightmap's position offset.
    /// \return The heightmap's position offset.
    public: gz::math::Vector3d Position() const;

    /// \brief Set the heightmap's position offset.
    /// \return The heightmap's position offset.
    public: void SetPosition(const gz::math::Vector3d &_position);

    /// \brief Get whether the heightmap uses terrain paging.
    /// \return True if the heightmap uses terrain paging.
    public: bool UseTerrainPaging() const;

    /// \brief Set whether the heightmap uses terrain paging. Defaults to false.
    /// \param[in] _use True to use.
    public: void SetUseTerrainPaging(bool _use);

    /// \brief Get the heightmap's sampling per datum.
    /// \return The heightmap's sampling.
    public: unsigned int Sampling() const;

    /// \brief Set the heightmap's sampling. Defaults to 1.
    /// \param[in] _sampling The heightmap's sampling per datum.
    public: void SetSampling(unsigned int _sampling);

    /// \brief Get the number of heightmap textures.
    /// \return Number of heightmap textures contained in this Heightmap object.
    public: uint64_t TextureCount() const;

    /// \brief Get a heightmap texture based on an index.
    /// \param[in] _index Index of the heightmap texture. The index should be in
    /// the range [0..TextureCount()).
    /// \return Pointer to the heightmap texture. Nullptr if the index does not
    /// exist.
    /// \sa uint64_t TextureCount() const
    public: const HeightmapTexture *TextureByIndex(uint64_t _index) const;

    /// \brief Add a heightmap texture.
    /// \param[in] _texture Texture to add.
    public: void AddTexture(const HeightmapTexture &_texture);

    /// \brief Get the number of heightmap blends.
    /// \return Number of heightmap blends contained in this Heightmap object.
    public: uint64_t BlendCount() const;

    /// \brief Get a heightmap blend based on an index.
    /// \param[in] _index Index of the heightmap blend. The index should be in
    /// the range [0..BlendCount()).
    /// \return Pointer to the heightmap blend. Nullptr if the index does not
    /// exist.
    /// \sa uint64_t BlendCount() const
    public: const HeightmapBlend *BlendByIndex(uint64_t _index) const;

    /// \brief Add a heightmap blend.
    /// \param[in] _blend Blend to add.
    public: void AddBlend(const HeightmapBlend &_blend);

    /// \brief Get a pointer to the SDF element that was used during load.
    /// \return SDF element pointer. The value will be nullptr if Load has
    /// not been called.
    public: sdf::ElementPtr Element() const;

    /// \brief Create and return an SDF element filled with data from this
    /// heightmap.
    /// Note that parameter passing functionality is not captured with this
    /// function.
    /// \return SDF element pointer with updated heightmap values.
    public: sdf::ElementPtr ToElement() const;

    /// \brief Create and return an SDF element filled with data from this
    /// heightmap.
    /// Note that parameter passing functionality is not captured with this
    /// function.
    /// \param[out] _errors Vector of errors.
    /// \return SDF element pointer with updated heightmap values.
    public: sdf::ElementPtr ToElement(sdf::Errors &_errors) const;

    /// \brief Private data pointer.
    GZ_UTILS_IMPL_PTR(dataPtr)
  };
  }
}
#endif
