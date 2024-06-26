#ifndef EndcapGeometry_h
#define EndcapGeometry_h

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

#include "Constants.h"

#include "HeterogeneousCore/AlpakaInterface/interface/host.h"

namespace SDL {
  template <typename TDev>
  class EndcapGeometry {};
  template <>
  class EndcapGeometry<SDL::Dev> {
  private:
    std::map<unsigned int, float> dxdy_slope_;     // dx/dy slope
    std::map<unsigned int, float> centroid_phis_;  // centroid phi

  public:
    Buf<SDL::Dev, unsigned int> geoMapDetId_buf;
    Buf<SDL::Dev, float> geoMapPhi_buf;

    unsigned int nEndCapMap;

    EndcapGeometry(Dev const& devAccIn, unsigned int sizef = endcap_size);
    EndcapGeometry(Dev const& devAccIn, QueueAcc& queue, std::string filename, unsigned int sizef = endcap_size);
    ~EndcapGeometry() = default;

    void load(QueueAcc& queue, std::string);

    void fillGeoMapArraysExplicit(QueueAcc& queue);
    float getdxdy_slope(unsigned int detid);
  };
}  // namespace SDL

#endif
