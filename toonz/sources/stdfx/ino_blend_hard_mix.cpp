//------------------------------------------------------------
#include "tfxparam.h"
#include "stdfx.h"

#include "ino_common.h"
#include "igs_color_blend.h"
/* tnzbase --> Source Files --> tfx --> binaryFx.cppを参照 */
class ino_blend_hard_mix final : public TBlendForeBackRasterFx {
  FX_PLUGIN_DECLARATION(ino_blend_hard_mix)

public:
  ino_blend_hard_mix() : TBlendForeBackRasterFx(true) {}
  ~ino_blend_hard_mix() {}
  void brendKernel(double& dnr, double& dng, double& dnb, double& dna,
                   const double upr, double upg, double upb, double upa,
                   const double up_opacity,
                   const bool alpha_rendering_sw = true) override {
    igs::color::hard_mix(dnr, dng, dnb, dna, upr, upg, upb, upa, up_opacity);
  }
};
FX_PLUGIN_IDENTIFIER(ino_blend_hard_mix, "inoHardMixFx");
