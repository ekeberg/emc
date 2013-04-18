#include "configuration.h"
 
Configuration read_configuration_file(const char *filename)
{
  Configuration config_out;
  config_t config;
  config_init(&config);
  if (!config_read_file(&config,filename)) {
    fprintf(stderr,"%d - %s\n",
	   config_error_line(&config),
	   config_error_text(&config));
    config_destroy(&config);
    exit(1);
  }
  config_lookup_int(&config,"model_side",&config_out.model_side);
  config_lookup_int(&config,"read_stride",&config_out.read_stride);
  config_lookup_float(&config,"wavelength",&config_out.wavelength);
  config_lookup_float(&config,"pixel_size",&config_out.pixel_size);
  config_lookup_int(&config,"detector_size",&config_out.detector_size);
  config_lookup_float(&config,"detector_distance",&config_out.detector_distance);
  //config_lookup_int(&config,"rotations_n",&config_out.rotations_n);
  config_lookup_string(&config,"rotations_file",&config_out.rotations_file);
  config_lookup_float(&config,"sigma_start",&config_out.sigma_start);
  config_lookup_float(&config,"sigma_final",&config_out.sigma_final);
  config_lookup_int(&config,"sigma_half_life",&config_out.sigma_half_life);
  config_lookup_int(&config,"slice_chunk",&config_out.slice_chunk);
  config_lookup_int(&config,"N_images",&config_out.N_images);
  config_lookup_int(&config,"max_iterations",&config_out.max_iterations);
  config_lookup_bool(&config,"blur_image",&config_out.blur_image);
  config_lookup_float(&config,"blur_sigma",&config_out.blur_sigma);
  config_lookup_string(&config,"mask_file",&config_out.mask_file);
  config_lookup_string(&config,"image_prefix",&config_out.image_prefix);
  config_lookup_bool(&config,"normalize_images",&config_out.normalize_images);
  config_lookup_bool(&config,"known_intensity",&config_out.known_intensity);
  config_lookup_int(&config,"model_input",&config_out.model_input);
  config_lookup_float(&config,"initial_model_noise",&config_out.initial_model_noise);
  config_lookup_string(&config,"model_file",&config_out.model_file);
  config_lookup_string(&config, "init_rotations", &config_out.init_rotations_file);
  config_lookup_bool(&config,"exclude_images",&config_out.exclude_images);
  config_lookup_float(&config,"exclude_ratio",&config_out.exclude_ratio);
  const char *diff_type_string = malloc(20*sizeof(char));
  config_lookup_string(&config,"diff_type",&diff_type_string);
  if (strcmp(diff_type_string, "absolute") == 0) {
    config_out.diff = absolute;
  } else if (strcmp(diff_type_string, "poisson") == 0) {
    config_out.diff = poisson;
  } else if (strcmp(diff_type_string, "relative") == 0) {
    config_out.diff = relative;
  }
  config_lookup_float(&config,"model_blur",&config_out.model_blur);

  config_destroy(&config);
  config_out.pixel_size *= config_out.read_stride;
  return config_out;
}

/* Dummy function at the moment */
int write_configuration_file(const char *filename, const Configuration config_in) {
  //FILE *output_stream = fopen(filename, 'wp');
  //config
  config_t config;
  config_init(&config);
}
